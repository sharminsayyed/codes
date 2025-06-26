/*
* Create an Android Application that Demonstrate TimePicker and display Selected Time on
TextView. */
package com.example.slip16qs2;

import android.app.TimePickerDialog;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.TimePicker;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

import java.util.Calendar;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main); // connect to xml file
        //find view by id
        TextView showtime = findViewById(R.id.textView2);
        Button timebtn = findViewById(R.id.button2);
        // on click to time btn show the timepicker dialog box
        timebtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // get the current time
                Calendar cal = Calendar.getInstance();
                int hour = cal.get(Calendar.HOUR_OF_DAY);
                int minutes = cal.get(Calendar.MINUTE);
                // create a time picker dialog
                TimePickerDialog tp = new TimePickerDialog(MainActivity.this,
                        new TimePickerDialog.OnTimeSetListener() {
                            @Override
                            public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
                                String time = "Selected Time :"+String.format("%02d",hourOfDay)+":"+String.format("%02d", minute);
                                showtime.setText(time);
                            }
                        },hour,minutes,true);
                tp.show();
            }
        });
    }
}