package com.example.slip11qs2;
import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class result extends  AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_result);//connect to xml file
        //find view by id
        TextView info = findViewById(R.id.displayinfo);
        String fnm = getIntent().getStringExtra("Firstname");
        String mnm = getIntent().getStringExtra("Middlename");
        String lnm = getIntent().getStringExtra("Lastname");
        String dob = getIntent().getStringExtra("DateOfBirth");
        String address = getIntent().getStringExtra("Address");
        String email = getIntent().getStringExtra("Email");
        String msg = " Name :" + fnm + " " + mnm + " " + lnm +
                "\n Date OF Birth : " + dob +
                "\n Address :" + address +
                "\n Email :" + email;

        info.setText(msg);
    }
}
