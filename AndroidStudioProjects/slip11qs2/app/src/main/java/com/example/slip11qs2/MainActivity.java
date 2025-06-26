/* Create First Activity to accept information like Student First Name, Middle Name, Last Name,
Date of birth, Address, Email ID and display all information on Second Activity when user click on
the Submit button.
 Create First Activity to accept information like Employee First Name, Middle Name, Last Name,
Salary, Address, Email ID and display all information on Second Activity when user click on Submit
button. (slip15) */
package com.example.slip11qs2;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    EditText fnm,lnm,mnm,dob,email,address;
    Button btn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main); // connect to xml
        //find view by ids
        fnm=findViewById(R.id.fnm);
        mnm=findViewById(R.id.mnm);
        lnm=findViewById(R.id.lnm);
        dob=findViewById(R.id.dob);
        address=findViewById(R.id.address);
        email=findViewById(R.id.email);
        btn=findViewById(R.id.button);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, result.class);
                intent.putExtra("Firstname",fnm.getText().toString());
                intent.putExtra("Middlename",mnm.getText().toString());
                intent.putExtra("Lastname",lnm.getText().toString());
                intent.putExtra("DateOfBirth",dob.getText().toString());
                intent.putExtra("Address",address.getText().toString());
                intent.putExtra("Email",email.getText().toString());
                startActivity(intent);
            }
        });


    }
}