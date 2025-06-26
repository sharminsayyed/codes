/*Create a Simple Application Which Send ―Hi‖ message from one activity to another with help
of Button (Use Intent). */
package com.example.slip12qs1;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // find view by id
        Button btn = findViewById(R.id.button);
        // on click of button perform following
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // create intent
                Intent intent = new Intent(MainActivity.this, result.class);
                intent.putExtra("message","Hii !");
                startActivity(intent);
            }
        });


    }
}