package com.example.slip20qs1;


import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    boolean isimage1 =true;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main); // connect to xml file
        // find view by id
        ImageView image = findViewById(R.id.imageView);
        Button btn = findViewById(R.id.button);
        // on click of button perform the particular tasks
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(isimage1){
                    image.setImageResource(R.drawable.lightimg3);
                }
                else{
                    image.setImageResource(R.drawable.lightimg2);
                }
                isimage1 = !isimage1;
            }

        });
    }
}