/*Create an android Application for performing the following operation on the table
Customer (id, name, address, phno). (use SQLite database)
i) Insert New Customer Details.
ii) Show All the Customer Details on Toast Message.*/
package com.example.slip4qs2;
import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    EditText name ,phone ,address;
    Button insert ,showall;
    DatabaseHelper dbhelper;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main); // connect to xml
        name = findViewById(R.id.name);
        address =findViewById(R.id.address);
        phone=findViewById(R.id.phone);
        insert=findViewById(R.id.insert);
        showall =findViewById(R.id.showall);

        dbhelper = new DatabaseHelper(this);
        // on click of insert button insert the record and display the message
        insert.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // conversion
                String nm = name.getText().toString();
                String addr = address.getText().toString();
                String phn = phone.getText().toString();
                if(nm.isEmpty() || addr.isEmpty() || phn.isEmpty()){
                    Toast.makeText(MainActivity.this,"Pleas fill all the fields ",Toast.LENGTH_LONG).show();
                }
                else{ // insert it in the company table
                    boolean isInserted  =dbhelper.insertCustomer(nm,addr,phn);
                    if(isInserted){ // if it is inserted successfully display a toast and set all feilds empty
                        Toast.makeText(MainActivity.this,"Details entered Successfully !",Toast.LENGTH_LONG).show();
                        name.setText("");
                        address.setText("");
                        phone.setText("");
                    }
                    else {  // if not inserted
                        Toast.makeText(MainActivity.this,"Failed to Insert !",Toast.LENGTH_LONG).show();
                    }
                }
            }
        });
        showall.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                Intent intent = new Intent(MainActivity.this , showAllCustomerDetails.class);
//                startActivity(intent);
                displayCutomers();

            }
        });

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
        Toast.makeText(MainActivity.this,data.toString(),Toast.LENGTH_LONG).show();
    }
}