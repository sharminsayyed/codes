/*Create an Android Application to find the factorial of a number and Display the Result on
Alert Box. */
package com.example.slip3qs2;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
public class MainActivity extends AppCompatActivity {
    EditText number ;
    Button btn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main); // connect to xml file
        //find view by id
        number = findViewById(R.id.number);
        btn = findViewById(R.id.button);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // conversion and checking
                String input = number.getText().toString();
                if(input.isEmpty()){
                    showAlert("Error","Please enter a number");
                    return ;
                }
                long num = Integer.parseInt(input);
                long fact =1;
                for(int i= 1;i <= num; i++) fact *= i;
                showAlert("Factorial Result :","Factorial of "+num+" is :"+fact);
            }
        });

    }
    private void showAlert(String title ,String message){
        AlertDialog.Builder builder = new AlertDialog.Builder(this); // create a builder for alert
        builder.setTitle(title); // set the title and message
        builder.setMessage(message);
        builder.setPositiveButton("OK",null); // set the button
        AlertDialog alert = builder.create(); // create an alert dialog
        alert.show(); // show the alert
    }
}