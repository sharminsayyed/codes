package com.example.slip11qs1;
import android.graphics.Color;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.SeekBar;
import android.widget.Spinner;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView textView = findViewById(R.id.textView);
        Spinner colorSpinner = findViewById(R.id.colorSpinner);
        Spinner fontSpinner = findViewById(R.id.fontSpinner);
        SeekBar sizeSeekBar = findViewById(R.id.sizeSeekBar);
        String[] colors = {"Black", "Red", "Blue", "Green"};
        String[] fonts = {"sans-serif", "serif", "monospace"};
        ArrayAdapter<String> colorAdapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_dropdown_item, colors);
        ArrayAdapter<String> fontAdapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_dropdown_item, fonts);
        colorSpinner.setAdapter(colorAdapter);
        fontSpinner.setAdapter(fontAdapter);
        colorSpinner.setOnItemSelectedListener(new android.widget.AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(android.widget.AdapterView<?> parent, android.view.View view, int position, long id) {
                switch (position) {
                    case 0: textView.setTextColor(Color.BLACK); break;
                    case 1: textView.setTextColor(Color.RED); break;
                    case 2: textView.setTextColor(Color.BLUE); break;
                    case 3: textView.setTextColor(Color.GREEN); break;
                }
            }
            @Override public void onNothingSelected(android.widget.AdapterView<?> parent) {}
        });
        fontSpinner.setOnItemSelectedListener(new android.widget.AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(android.widget.AdapterView<?> parent, android.view.View view, int position, long id) {
                textView.setTypeface(android.graphics.Typeface.create(fonts[position], android.graphics.Typeface.NORMAL));
            }
            @Override public void onNothingSelected(android.widget.AdapterView<?> parent) {}
        });
        sizeSeekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                textView.setTextSize(progress + 10);
            }
            @Override public void onStartTrackingTouch(SeekBar seekBar) {}
            @Override public void onStopTrackingTouch(SeekBar seekBar) {}
        });
    }
}
