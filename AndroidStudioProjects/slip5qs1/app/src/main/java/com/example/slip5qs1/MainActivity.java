
/*Create an Android Application to accept two numbers and find power and Average.
Display the result on the next activity on Button click. */
package com.example.slip5qs1;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    EditText etnum1, etnum2;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // find view by ids
        etnum1 = findViewById(R.id.etnum1);
        etnum2 = findViewById(R.id.etnum2);
        Button btn = findViewById(R.id.btn);

        // on click of button perform the particular activity
        btn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                double num1 = Double.parseDouble(etnum1.getText().toString());
                double num2= Double.parseDouble(etnum2.getText().toString());
                double pow = Math.pow(num1,num2);
                double avg = (num1 +num2)/2;
                // use intent to switch activity and pass the power and average to another activity to display
                Intent intent = new Intent(MainActivity.this,result.class);
                intent.putExtra("Power" , pow);
                intent.putExtra("Average",avg);
                startActivity(intent);
            }
        });
    }
}