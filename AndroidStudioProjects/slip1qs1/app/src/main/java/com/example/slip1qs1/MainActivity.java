/*
* Create a Simple Application which shows the Life Cycle of Activity.*/
package com.example.slip1qs1;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    TextView textView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = findViewById(R.id.textview);
        logAndDisplay("onCreate()");
    }
    private void logAndDisplay(String event){
        Log.d("Activity lifecycle :",event);
        textView.append("\n"+event);
    }
    protected void onStart(){
        super.onStart();
        logAndDisplay("onStart()");
    }
    protected void onResume(){
        super.onResume();
        logAndDisplay("onResume()");
    }
    protected void onPause(){
        super.onPause();
        logAndDisplay("onPause()");
    }
    protected void onStop(){
        super.onStop();
        logAndDisplay("onStop()");
    }
    protected void onDestroy(){
        super.onDestroy();
        logAndDisplay("onDestroy()");
    }
    protected void onRestart(){
        super.onRestart();
        logAndDisplay("onRestart()");
    }
}