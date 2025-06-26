/*Write an Android application to accept two numbers from the user, and display them, but
reject input if both numbers are greater than 10 and asks for two new numbers. */

package com.example.slip8qs1;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main); // connect the xml file
        EditText etusername = findViewById(R.id.username); // find view by id
        EditText etpassword = findViewById(R.id.password);
        Button btn = findViewById(R.id.btn); // on click of button perform the particular activity
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String username = etusername.getText().toString();   // conversion
                String password = etpassword.getText().toString();
                // check if username and password is correct
                if(!username.isEmpty() && !password.isEmpty()){
                    if(username.equals("user") && password.equals("pass")){
                        Toast.makeText(MainActivity.this ,"Login Successful !",Toast.LENGTH_LONG).show(); // show toast after login
                        // create intent
                        Intent intent = new Intent(MainActivity.this,result.class);
                        startActivity(intent);
                    }
                    else{
                        Toast.makeText(MainActivity.this,"invalid username and password",Toast.LENGTH_LONG).show();
                    }
                }
                else{
                    Toast.makeText(MainActivity.this,"enter username and password",Toast.LENGTH_LONG).show();
                }
            }
        });

    }
}