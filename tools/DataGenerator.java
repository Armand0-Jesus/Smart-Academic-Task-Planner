import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class DataGenerator {
    private static final int DEFAULT_TASK_COUNT = 25;
    private static final int MAX_TASK_COUNT = 250;
    private static final DateTimeFormatter DATE_FORMAT = DateTimeFormatter.ofPattern("dd/MM/yyyy");
    private static final String[] COURSES = {
        "COMP2501", "COMP3015", "COMP3075", "MATE3171", "INGL3101", "ESPA3101"
    };
    private static final String[] TITLES = {
        "Estudiar examen", "Completar laboratorio", "Preparar presentacion",
        "Leer capitulos", "Entregar proyecto", "Repasar ejercicios",
        "Organizar notas", "Investigar tema", "Completar ensayo"
    };
    private static final String[] DESCRIPTIONS = {
        "Practicar conceptos importantes del curso",
        "Completar los requisitos antes de la fecha limite",
        "Revisar materiales y ejemplos dados en clase",
        "Preparar evidencia para entregas academicas",
        "Validar resultados y corregir errores encontrados"
    };
    private static final String[] STATUSES = {
        "Pendiente", "En Progreso", "Completada"
    };

    private static class TaskRecord {
        private final int id;
        private final String title;
        private final String description;
        private final String course;
        private final int priority;
        private final String dueDate;
        private final String status;

        TaskRecord(int id, String title, String description, String course, int priority, String dueDate, String status) {
            this.id = id;
            this.title = title;
            this.description = description;
            this.course = course;
            this.priority = priority;
            this.dueDate = dueDate;
            this.status = status;
        }
    }

    private static class DependencyRecord {
        private final int prerequisiteId;
        private final int dependentId;

        DependencyRecord(int prerequisiteId, int dependentId) {
            this.prerequisiteId = prerequisiteId;
            this.dependentId = dependentId;
        }
    }

    public static void main(String[] args) throws IOException {
        Path outputDirectory = args.length >= 1 ? Paths.get(args[0]) : Paths.get("generated-data");
        int taskCount = args.length >= 2 ? parseTaskCount(args[1]) : DEFAULT_TASK_COUNT;

        Files.createDirectories(outputDirectory);

        Random random = new Random(2501);
        List<TaskRecord> tasks = generateTasks(taskCount, random);
        List<DependencyRecord> dependencies = generateDependencies(tasks, random);
        List<String> history = generateHistory(tasks, dependencies);

        writeTasks(outputDirectory.resolve("tasks.txt"), tasks);
        writeDependencies(outputDirectory.resolve("dependencies.txt"), dependencies);
        writeHistory(outputDirectory.resolve("history.txt"), history);
        writeReport(outputDirectory.resolve("task_report.txt"), tasks, dependencies);

        System.out.println("Dataset generado en: " + outputDirectory.toAbsolutePath());
        System.out.println("Tareas generadas: " + tasks.size());
        System.out.println("Dependencias generadas: " + dependencies.size());
    }

    private static int parseTaskCount(String value) {
        try {
            int taskCount = Integer.parseInt(value);

            if (taskCount < 1 || taskCount > MAX_TASK_COUNT) {
                throw new IllegalArgumentException("La cantidad debe estar entre 1 y " + MAX_TASK_COUNT + ".");
            }

            return taskCount;
        } catch (NumberFormatException exception) {
            throw new IllegalArgumentException("La cantidad de tareas debe ser un numero entero.", exception);
        }
    }

    private static List<TaskRecord> generateTasks(int taskCount, Random random) {
        List<TaskRecord> tasks = new ArrayList<>();
        LocalDate startDate = LocalDate.now().plusDays(1);

        for (int i = 1; i <= taskCount; i++) {
            int id = 1000 + i;
            String title = TITLES[random.nextInt(TITLES.length)] + " " + i;
            String description = DESCRIPTIONS[random.nextInt(DESCRIPTIONS.length)];
            String course = COURSES[random.nextInt(COURSES.length)];
            int priority = random.nextInt(3) + 1;
            String dueDate = startDate.plusDays(random.nextInt(45)).format(DATE_FORMAT);
            String status = STATUSES[random.nextInt(STATUSES.length)];

            tasks.add(new TaskRecord(id, title, description, course, priority, dueDate, status));
        }

        return tasks;
    }

    private static List<DependencyRecord> generateDependencies(List<TaskRecord> tasks, Random random) {
        List<DependencyRecord> dependencies = new ArrayList<>();

        for (int dependentIndex = 1; dependentIndex < tasks.size(); dependentIndex++) {
            if (random.nextBoolean()) {
                int prerequisiteIndex = random.nextInt(dependentIndex);
                int prerequisiteId = tasks.get(prerequisiteIndex).id;
                int dependentId = tasks.get(dependentIndex).id;

                dependencies.add(new DependencyRecord(prerequisiteId, dependentId));
            }
        }

        return dependencies;
    }

    private static List<String> generateHistory(List<TaskRecord> tasks, List<DependencyRecord> dependencies) {
        List<String> history = new ArrayList<>();

        for (TaskRecord task : tasks) {
            history.add("Crea tarea con ID " + task.id);
        }

        for (DependencyRecord dependency : dependencies) {
            history.add("Se agrego depedencia: La tarea " + dependency.dependentId
                + " depende de la Tarea " + dependency.prerequisiteId);
        }

        history.add("Dataset de prueba generado desde DataGenerator.java");

        return history;
    }

    private static void writeTasks(Path path, List<TaskRecord> tasks) throws IOException {
        try (BufferedWriter writer = Files.newBufferedWriter(path)) {
            for (TaskRecord task : tasks) {
                writer.write(task.id + "|"
                    + task.title + "|"
                    + task.description + "|"
                    + task.course + "|"
                    + task.priority + "|"
                    + task.dueDate + "|"
                    + task.status);
                writer.newLine();
            }
        }
    }

    private static void writeDependencies(Path path, List<DependencyRecord> dependencies) throws IOException {
        try (BufferedWriter writer = Files.newBufferedWriter(path)) {
            for (DependencyRecord dependency : dependencies) {
                writer.write(dependency.prerequisiteId + "|" + dependency.dependentId);
                writer.newLine();
            }
        }
    }

    private static void writeHistory(Path path, List<String> history) throws IOException {
        try (BufferedWriter writer = Files.newBufferedWriter(path)) {
            for (String action : history) {
                writer.write(action);
                writer.newLine();
            }
        }
    }

    private static void writeReport(Path path, List<TaskRecord> tasks, List<DependencyRecord> dependencies)
        throws IOException {
        int pending = 0;
        int inProgress = 0;
        int completed = 0;
        int highPriority = 0;

        for (TaskRecord task : tasks) {
            if (task.status.equals("Pendiente")) {
                pending++;
            } else if (task.status.equals("En Progreso")) {
                inProgress++;
            } else if (task.status.equals("Completada")) {
                completed++;
            }

            if (task.priority == 1) {
                highPriority++;
            }
        }

        try (BufferedWriter writer = Files.newBufferedWriter(path)) {
            writer.write("REPORTE DE DATASET DE TAREAS");
            writer.newLine();
            writer.write("============================");
            writer.newLine();
            writer.write("Total de tareas: " + tasks.size());
            writer.newLine();
            writer.write("Tareas pendientes: " + pending);
            writer.newLine();
            writer.write("Tareas en progreso: " + inProgress);
            writer.newLine();
            writer.write("Tareas completadas: " + completed);
            writer.newLine();
            writer.write("Tareas de prioridad alta: " + highPriority);
            writer.newLine();
            writer.write("Dependencias registradas: " + dependencies.size());
            writer.newLine();
        }
    }
}
