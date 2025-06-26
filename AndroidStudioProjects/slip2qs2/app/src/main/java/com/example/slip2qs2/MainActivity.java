package com.example.slip2qs2;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    // Start the music service
    public void startMusic(View view) {
        startService(new Intent(this, MusicService.class));
    }

    // Stop the music service
    public void stopMusic(View view) {
        stopService(new Intent(this, MusicService.class));
    }
}
