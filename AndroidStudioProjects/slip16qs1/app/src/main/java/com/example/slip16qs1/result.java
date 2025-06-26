package com.example.slip16qs1;

import android.os.Bundle;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
public class result extends AppCompatActivity {
    TableLayout tablelayout;
    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_result); // connect the xml
        // find view by id
         tablelayout = findViewById(R.id.tablelayout);
        // get info from the intent
        String name = getIntent().getStringExtra("NAME");
        String surname = getIntent().getStringExtra("SURNAME");
        String classs = getIntent().getStringExtra("CLASS");
        String gender = getIntent().getStringExtra("GENDER");
        String hobbies = getIntent().getStringExtra("HOBBIES");
        String marks = getIntent().getStringExtra("MARKS");

        // as we have to display the information in table add them in rows one by one
        addrow("Name : ",name);
        addrow("Surname : ",surname);
        addrow("Class : ",classs);
        addrow("Gender : ",gender);
        addrow("Hobbies : ",hobbies);
        addrow("Marks : ",marks);


    }
    private void addrow(String label , String value){
        TableRow row = new TableRow(this);
        TextView labelview = new TextView(this);
        TextView valueview = new TextView(this);
        // setting and adding labels and value in the row
        labelview.setText(label);
        labelview.setTextSize(20);
        row.addView(labelview);
        valueview.setText(value);
        valueview.setTextSize(20);
        row.addView(valueview);;
        // adding the row in the table
        tablelayout.addView(row);

    }
}
