package com.example;
import java.io.*;
import java.util.*;

class Grocery extends ShoppingItem {
    private String expiryDate;

    public Grocery(String name, double price, String expiryDate) {
        super(name, price);
        this.expiryDate = expiryDate;
    }

    @Override
    public String getType() {
        return "Grocery";
    }

    @Override
    public String getSpecialInfo() {
        return expiryDate;
    }
}