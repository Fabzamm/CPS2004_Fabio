package com.example;
import java.io.*;
import java.util.*;


public class ShoppingApp {
    private static final String FILE_PATH = "shopping_items.txt";
    private final List<ShoppingItem> items = new ArrayList<>();
    private final List<ShoppingItem> duplicateItems = new ArrayList<>();  // New collection for duplicated items

    // Method to add item to the main list
    public void addItem(ShoppingItem item) {
        items.add(item);
    }

    // Method to add item to the duplicated list
    public void addDuplicateItem(ShoppingItem item) {
        duplicateItems.add(item);
    }

    // Method to display all items in the collection
    public void displayItems() {
        System.out.println("Original Items:");
        if (items.isEmpty()) {
            System.out.println("No items in the collection.");
        } else {
            items.forEach(System.out::println);
        }

        System.out.println("\nDuplicated Items:");
        if (duplicateItems.isEmpty()) {
            System.out.println("No duplicated items.");
        } else {
            duplicateItems.forEach(System.out::println);
        }
    }

    // Method to save both lists of items to a file
    public void saveItems() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_PATH))) {
            for (ShoppingItem item : items) {
                writer.write(item.toFileFormat());
                writer.newLine();
            }
            for (ShoppingItem item : duplicateItems) {
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

    // Duplicate a selected item from the original collection and add it to the duplicate collection
    public void duplicateItem(int index) {
        if (index >= 0 && index < items.size()) {
            ShoppingItem item = items.get(index);
            ShoppingItem duplicate = createDuplicate(item);
            duplicateItems.add(duplicate);  // Add the duplicate to the second collection
            System.out.println("Item duplicated successfully!");
        } else {
            System.out.println("Invalid index. Cannot duplicate item.");
        }
    }

    // Helper method to create a duplicate (a new instance of the item)
    private ShoppingItem createDuplicate(ShoppingItem item) {
        switch (item.getType()) {
            case "Grocery":
                Grocery grocery = (Grocery) item;
                return new Grocery(grocery.name, grocery.price, grocery.getSpecialInfo());
            case "Electronics":
                Electronics electronics = (Electronics) item;
                return new Electronics(electronics.name, electronics.price, electronics.getSpecialInfo());
            default:
                throw new IllegalArgumentException("Unknown item type: " + item.getType());
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
            System.out.println("3. Duplicate an item");
            System.out.println("4. Exit");
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
                    System.out.print("Enter the index of the item to duplicate: ");
                    int index = scanner.nextInt();
                    app.duplicateItem(index);
                }
                case 4 -> {
                    app.saveItems();
                    System.out.println("Goodbye!");
                    return;
                }
                default -> System.out.println("Invalid choice.");
            }
        }
    }
}