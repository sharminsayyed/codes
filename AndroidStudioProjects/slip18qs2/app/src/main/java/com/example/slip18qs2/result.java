package com.example.slip18qs2;
import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class result extends AppCompatActivity{
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_result); // connect to xml
        // find view by id
        TextView resultttext = findViewById(R.id.result);
        double result = getIntent().getDoubleExtra("Result",0); // get the value from the intent
        resultttext.setText("Result is :"+result);
    }
}
