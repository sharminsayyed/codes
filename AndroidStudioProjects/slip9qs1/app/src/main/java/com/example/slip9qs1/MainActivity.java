/*
 Write an Android application to accept two numbers from the user, and display them, but
reject input if both numbers are greater than 10 and asks for two new numbers. */
package com.example.slip9qs1;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

import com.example.slip9qs1.result;
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main); // connect to xml file
        // find view by id
        TextView num1  = findViewById(R.id.number1);
        TextView num2 = findViewById(R.id.number2);
        Button btn = findViewById(R.id.button);
        // on click of button do the following
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // conversion
                int number1 =Integer.parseInt(num1.getText().toString());
                int number2 = Integer.parseInt(num2.getText().toString());
                // logic
                if(number1 > 10 && number2 >10){
                    Toast.makeText(MainActivity.this,"Both numbers are greater than 10 .please enter new number",Toast.LENGTH_LONG).show();
                    // set the blank space
                    num1.setText("");
                    num2.setText("");
                }
                else{
                    Toast.makeText(MainActivity.this,"number 1 :"+number1+"number 2 :"+number2,Toast.LENGTH_LONG).show();
                    // or
                    Intent intent = new Intent(MainActivity.this, result.class);
                    intent.putExtra("number1",number1);
                    intent.putExtra("number2",number2);
                    startActivity(intent);

                }
            }
        });

    }
}