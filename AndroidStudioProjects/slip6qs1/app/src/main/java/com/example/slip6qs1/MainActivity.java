/* Create a Simple Application Which Send ―Hello! message from one activity to another with
help of Button (Use Intent).*/
package com.example.slip6qs1;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    Button btn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // find the view by id
        btn = findViewById(R.id.btn);
        // on click of the button display message
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this , result.class);
                intent.putExtra("message","Helloo !");
                startActivity(intent);
            }
        });

    }
}