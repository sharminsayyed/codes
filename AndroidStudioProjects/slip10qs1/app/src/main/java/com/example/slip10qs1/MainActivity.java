/*
* . Create an Android Application that Demonstrate Switch and Toggle Button.*/
package com.example.slip10qs1;

import android.os.Bundle;
import android.widget.CompoundButton;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.ToggleButton;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);// connect xml file
        //find views by id
        Switch switchbtn = findViewById(R.id.switch1);
        ToggleButton togglebtn = findViewById(R.id.toggleButton);
        TextView resulttoggle = findViewById(R.id.result1);
        TextView resultswitch = findViewById(R.id.result2);
        // on checking the switch and toggle
        togglebtn.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if(isChecked)
                    resulttoggle.setText("Toggle is ON");
                else
                    resulttoggle.setText("Toggle is OFF");
            }
        });
        switchbtn.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if(isChecked)
                    resultswitch.setText("Switch is ON");
                else
                    resultswitch.setText("Switch is OFF");
            }
        });

    }
}