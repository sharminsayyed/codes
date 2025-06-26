package com.example.slip12qs1;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class result extends AppCompatActivity{
    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        // connect the xml file
        setContentView(R.layout.activity_result);
        // find view by id
        TextView result = findViewById(R.id.result);
        String msg = getIntent().getStringExtra("message");
        result.setText(msg);

    }
}
