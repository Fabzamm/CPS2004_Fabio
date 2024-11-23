package com.example;
import java.io.*;
import java.util.*;

abstract class ShoppingItem {
    protected String name;
    protected double price;

    public ShoppingItem(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public abstract String getType();

    public abstract String getSpecialInfo();

    @Override
    public String toString() {
        return String.format("Type: %s, Name: %s, Price: %.2f, Details: %s",
                getType(), name, price, getSpecialInfo());
    }

    public String toFileFormat() {
        return String.format("%s|%s|%.2f|%s", getType(), name, price, getSpecialInfo());
    }

    public static ShoppingItem fromFileFormat(String line) throws IllegalArgumentException {
        String[] parts = line.split("\\|");
        if (parts.length < 4) throw new IllegalArgumentException("Invalid item format: " + line);

        String type = parts[0];
        String name = parts[1];
        double price = Double.parseDouble(parts[2]);
        String details = parts[3];

        return switch (type) {
            case "Grocery" -> new Grocery(name, price, details);
            case "Electronics" -> new Electronics(name, price, details);
            default -> throw new IllegalArgumentException("Unknown type: " + type);
        };
    }
}