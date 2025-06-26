package com.example.slip8qs1;

import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
public class result extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceSate){
        super.onCreate(savedInstanceSate);
        setContentView(R.layout.activity_result); // connect the xml
        // find view by id
        TextView result = findViewById(R.id.result);
        result.setText("welcome to another activity");
    }
}
