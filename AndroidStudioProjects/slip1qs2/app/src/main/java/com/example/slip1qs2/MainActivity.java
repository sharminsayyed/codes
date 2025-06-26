/*
*  Create an Android Application that demonstrate DatePicker and DatePickerDailog.*/
package com.example.slip1qs2;
import android.app.DatePickerDialog;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.util.Calendar;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main); // connect to xml
        // find view by id
        TextView showdate = findViewById(R.id.textView);
        Button datebtn = findViewById(R.id.button);

        datebtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // get the today's date
                Calendar cal = Calendar.getInstance();
                int Year = cal.get(Calendar.YEAR);
                int Month = cal.get(Calendar.MONTH);
                int Day = cal.get(Calendar.DAY_OF_MONTH);
                // create a datepicker dialog box to select a date and show
                DatePickerDialog dp = new DatePickerDialog(MainActivity.this,
                        new DatePickerDialog.OnDateSetListener() {
                            @Override
                            public void onDateSet(DatePicker view, int year, int month, int dayOfMonth) {
                                showdate.setText("date :"+dayOfMonth+"/"+(month+1)+"/"+year);
                            }
                        },Year,Month,Day); // here when we click default show todays date
                dp.show();
            }
        });

    }
}
