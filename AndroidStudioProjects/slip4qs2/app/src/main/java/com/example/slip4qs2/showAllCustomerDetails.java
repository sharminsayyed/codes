package com.example.slip4qs2;

import android.database.Cursor;
import android.os.Bundle;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

public class showAllCustomerDetails extends AppCompatActivity {
    TextView result;
    DatabaseHelper dbhelper;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_result); // connect to xml
        // find view by id
        result=findViewById(R.id.textView);
        dbhelper = new DatabaseHelper(this);
        displayCutomers();
    }
    public void displayCutomers(){
        Cursor cursor = dbhelper.showAll();
        StringBuilder data = new StringBuilder();
        if(cursor.getCount() == 0){
            data.append("NO Companies found");
        }
        else{
            while(cursor.moveToNext()){
                data.append("ID : ").append(cursor.getInt(0)).append("\n");
                data.append("NAME : ").append(cursor.getString(1)).append("\n");
                data.append("ADDRESS : ").append(cursor.getString(2)).append("\n");
                data.append("PHONE : ").append(cursor.getString(3)).append("\n \n");
            }
        }
        result.setText(data.toString());
    }
}
