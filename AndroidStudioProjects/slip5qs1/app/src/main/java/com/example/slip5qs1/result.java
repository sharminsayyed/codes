package com.example.slip5qs1;

import android.os.Bundle;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class result extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.result);
        // find view from the result activity
        TextView result = findViewById(R.id.result);
        double pow = getIntent().getDoubleExtra("Power",0);
        double avg = getIntent().getDoubleExtra("Average",0);
        result.setText("Power : "+pow+"\n Average : "+avg);

    }
}
