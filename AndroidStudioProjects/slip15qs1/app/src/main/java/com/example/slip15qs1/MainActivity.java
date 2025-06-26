/*
* Design following-add a border to an Android Layout.*/
package com.example.slip15qs1;

import android.graphics.Color;
import android.graphics.drawable.GradientDrawable;
import android.os.Bundle;
import android.widget.LinearLayout;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        // find linear layout id
        LinearLayout layout = findViewById(R.id.main);
        // define gradient and set properties
        GradientDrawable background = new GradientDrawable();
        background.setStroke(70 , Color.WHITE);
        background.setCornerRadius(80f);
        background.setColor(Color.BLUE);
        // add background to the layout
        layout.setBackground(background);
    }
}