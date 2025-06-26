package com.example.slip19qs2;
import android.os.Bundle;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

public class result  extends  AppCompatActivity{
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_result);//connect to xml
        // find view by id
        TextView result = findViewById(R.id.result);
        // get all elements from the intent
        String name = getIntent().getStringExtra("nm");
        String currentw = getIntent().getStringExtra("cw");
        String goalw = getIntent().getStringExtra("gw");
        String height = getIntent().getStringExtra("h");
        String age = getIntent().getStringExtra("a");
        String phn = getIntent().getStringExtra("phn");
        String address = getIntent().getStringExtra("add");
        String gender = getIntent().getStringExtra("gen");
        String msg = " Full Name : "+name +
                "\n Gender : "+gender +
                "\n Current Weight : "+currentw+
                "\n Height : "+height+
                "\n Goal Weight : "+goalw+
                "\n Age : "+age+
                "\n Phone : "+phn +
                "\n Address : "+address;
        result.setText(msg);

    }
}
