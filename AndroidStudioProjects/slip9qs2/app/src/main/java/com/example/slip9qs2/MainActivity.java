/*Create table Company (id, name, address, phno). Create Application for Performing the
following operation on the table.
a) Insert New Company details.
b) Show All Company details*/
package com.example.slip9qs2;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    EditText name ,phone,address;
    Button insert ,showall;
    DatabaseHelper dbhelper;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main); // connect to xml file
        // find view by id
        name = findViewById(R.id.name);
        address =findViewById(R.id.address);
        phone = findViewById(R.id.phone);
        insert = findViewById(R.id.insert);
        showall=findViewById(R.id.showall);
        dbhelper = new DatabaseHelper(this);
        // on click of insert button insert the new details
        insert.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                 // conversion
                String nm = name.getText().toString();
                String addr = address.getText().toString();
                String phn = phone.getText().toString();
                if(nm.isEmpty() || addr.isEmpty() || phn.isEmpty()){
                    Toast.makeText(MainActivity.this,"please fill all the fields ",Toast.LENGTH_LONG).show();
                }
                else{
                    // insert it in the company table
                    boolean isInserted = dbhelper.insertComapny(nm,addr,phn);
                    if(isInserted){
                        // if it is inserted successfully display a toast and set all feilds empty
                        Toast.makeText(MainActivity.this,"Details Inserted Successfully !",Toast.LENGTH_LONG).show();
                        name.setText("");
                        address.setText("");
                        phone.setText("");
                    }
                    else{
                        // if not inserted
                        Toast.makeText(MainActivity.this,"Details Not Inserted !",Toast.LENGTH_LONG).show();

                    }
                }
            }
        });

        // on click  of show all details button
        showall.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, showAllCompanyDetails.class);
                startActivity(intent);
            }
        });

    }
}