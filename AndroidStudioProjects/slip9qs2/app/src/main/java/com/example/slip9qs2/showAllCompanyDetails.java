package com.example.slip9qs2;

import androidx.appcompat.app.AppCompatActivity;

import android.database.Cursor;
import android.os.Bundle;
import android.widget.TextView;


public class showAllCompanyDetails extends AppCompatActivity {

    TextView result;
    DatabaseHelper dbhelper;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_result); // connect to xml file
        // find view by id
        result =findViewById(R.id.companylist);
        dbhelper = new DatabaseHelper(this);
        displayComapnies();
    }
    public void displayComapnies(){
        Cursor cursor = dbhelper.showCompany();
        StringBuilder data = new StringBuilder(); // used to format the output
        if(cursor.getCount() == 0){
            data.append("NO Companies found");
        }
        else{
            while(cursor.moveToNext()){
                data.append("ID : ").append(cursor.getInt(0)).append("\n");
                data.append("NAME : ").append(cursor.getString(1)).append("\n");
                data.append("ADDRESS : ").append(cursor.getString(2)).append("\n");
                data.append("PHONE : ").append(cursor.getString(3)).append("\n");
            }
        }
        result.setText(data.toString());
    }
}
