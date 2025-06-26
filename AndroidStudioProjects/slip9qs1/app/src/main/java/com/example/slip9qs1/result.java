package com.example.slip9qs1;

import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class result extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedIstanceState){
        super.onCreate(savedIstanceState);
        setContentView(R.layout.activity_result); // connect the xml file
        // find view by id
        TextView result = findViewById(R.id.result);
        // get text from intent
        int number1 = getIntent().getIntExtra("number1",0);
        int number2 = getIntent().getIntExtra("number2",0);
        result.setText("number1 =" +number1+"\nnumber2 ="+number2);
    }
}
