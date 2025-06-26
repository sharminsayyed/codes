package com.example.slip6qs1;

import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
public class result extends AppCompatActivity{
    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        // connect with the activity
        setContentView(R.layout.activity_result);
        // find view by id
        TextView result = findViewById(R.id.result);
        String msg = getIntent().getStringExtra("message");
        result.setText(msg);

    }
}
