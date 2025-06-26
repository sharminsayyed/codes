/*
* . Create an Android Application that Demonstrate Radio Button.*/
package com.example.slip7qs1;

import android.os.Bundle;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main); // connect the xml file
        // find view by id
        RadioGroup group = findViewById(R.id.radiogroup);
        group.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                RadioButton selectedbtn = findViewById(checkedId); // pass the radio button which is checked
                if(selectedbtn != null){
                    // conversion
                    String gender = selectedbtn.getText().toString();
                    Toast.makeText(MainActivity.this,"you selected : "+gender+" category",Toast.LENGTH_LONG).show();
                }

            }
        });

    }
}