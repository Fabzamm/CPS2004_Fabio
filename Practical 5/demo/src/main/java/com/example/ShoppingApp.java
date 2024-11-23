package com.example;
import java.io.*;
import java.util.*;


public class ShoppingApp {
    private static final String FILE_PATH = "shopping_items.txt";
    private final List<ShoppingItem> items = new ArrayList<>();

    public void addItem(ShoppingItem item) {
        items.add(item);
    }

    public void displayItems() {
        if (items.isEmpty()) {
            System.out.println("No items in the collection.");
        } else {
            items.forEach(System.out::println);
        }
    }

    public void saveItems() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_PATH))) {
            for (ShoppingItem item : items) {
                writer.write(item.toFileFormat());
                writer.newLine();
            }
        } catch (IOException e) {
            System.err.println("Error saving items: " + e.getMessage());
        }
    }

    public void loadItems() {
        try (Scanner scanner = new Scanner(new FileInputStream(FILE_PATH))) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                try {
                    ShoppingItem item = ShoppingItem.fromFileFormat(line);
                    items.add(item);
                } catch (IllegalArgumentException e) {
                    System.err.println("Skipping invalid item: " + e.getMessage());
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("No existing file found. Starting fresh.");
        }
    }

    public static void main(String[] args) {
        ShoppingApp app = new ShoppingApp();
        app.loadItems();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to Shopping App!");
        while (true) {
            System.out.println("1. Add item");
            System.out.println("2. Display items");
            System.out.println("3. Exit");
            System.out.print("Choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline
            System.out.println(""); // New line

            switch (choice) {
                case 1 -> {
                    System.out.print("Enter type (Grocery/Electronics): ");
                    String type = scanner.nextLine();
                    System.out.print("Enter name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter price: ");
                    double price = scanner.nextDouble();
                    scanner.nextLine(); // Consume newline
                    System.out.print("Enter special info (Expiry Date for Grocery, Warranty for Electronics): ");
                    String specialInfo = scanner.nextLine();

                    try {
                        ShoppingItem item = switch (type) {
                            case "Grocery" -> new Grocery(name, price, specialInfo);
                            case "Electronics" -> new Electronics(name, price, specialInfo);
                            default -> throw new IllegalArgumentException("Invalid type!");
                        };
                        app.addItem(item);
                    } catch (IllegalArgumentException e) {
                        System.err.println("Error adding item: " + e.getMessage());
                    }
                }
                case 2 -> app.displayItems();
                case 3 -> {
                    app.saveItems();
                    System.out.println("Goodbye!");
                    return;
                }
                default -> System.out.println("Invalid choice.");
            }
        }
    }
}