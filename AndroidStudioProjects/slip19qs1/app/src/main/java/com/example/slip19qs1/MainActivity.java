/*
* Create an Android Application that on/off the bulb using Toggle Button */
package com.example.slip19qs1;

import android.os.Bundle;
import android.widget.CompoundButton;
import android.widget.ImageView;
import android.widget.ToggleButton;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main); // connect to xml file
        // find view by id
        ImageView image = findViewById(R.id.imageView);
        ToggleButton btn = findViewById(R.id.toggle);
        // on the movement of btn perform the particular task
        btn.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if(isChecked){
                    image.setImageResource(R.drawable.blub_on);
                }
                else{
                    image.setImageResource(R.drawable.blub_off);
                }
            }
        });
    }
}