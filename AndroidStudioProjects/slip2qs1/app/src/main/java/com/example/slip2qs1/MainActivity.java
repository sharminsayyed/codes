/*Create a Simple Application, which reads a positive number from the user and display its
factorial value in another activity. */
package com.example.slip2qs1;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        // connect the xml
        setContentView(R.layout.activity_main);
        // find view by id
        EditText inputnum = findViewById(R.id.number);
        Button btn = findViewById(R.id.btn);
        // on click of button display the factorial
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int num = Integer.parseInt(inputnum.getText().toString()); // conversion
                long fact =1; // calculate factorial
                for (int i= 1; i<= num; i++) fact *= i;
                // create intent
                Intent intent =new Intent(MainActivity.this, result.class);
                intent.putExtra("factorial",fact);
                startActivity(intent);
            }
        });
    }
}