package com.example;

import java.io.*;
import java.util.*;

class Electronics extends ShoppingItem {
    private String warranty;

    public Electronics(String name, double price, String warranty) {
        super(name, price);
        this.warranty = warranty;
    }

    @Override
    public String getType() {
        return "Electronics";
    }

    @Override
    public String getSpecialInfo() {
        return warranty;
    }
}

