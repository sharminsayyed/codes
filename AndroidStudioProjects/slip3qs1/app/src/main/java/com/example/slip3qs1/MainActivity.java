/*
* 1. Create an Android Application that will change color of the College Name on click of Push
Button and change the font size, font style of text view using xml. */
package com.example.slip3qs1;

import android.graphics.Color;import android.graphics.Typeface;import android.os.Bundle;import android.view.View;import android.widget.Button;import android.widget.TextView;import androidx.activity.EdgeToEdge;import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        // find view by id
        TextView result = findViewById(R.id.textView);
        Button btn = findViewById(R.id.button);
        // on click of button change the color , font and size
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                result.setTextSize(30);
                result.setTextColor(Color.BLUE);
                result.setTypeface(null , Typeface.BOLD_ITALIC);
            }
        });

    }
}