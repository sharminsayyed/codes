package com.example.slip2qs1;

import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
public class result extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceSate){
        super.onCreate(savedInstanceSate);
        // connect the xml file
        setContentView(R.layout.activity_result);
        // find view
        TextView result = findViewById(R.id.result);
        // take from the intent
        long fact = getIntent().getLongExtra("factorial",1);
        // display
        result.setText("Factorial : "+fact);
    }
}
