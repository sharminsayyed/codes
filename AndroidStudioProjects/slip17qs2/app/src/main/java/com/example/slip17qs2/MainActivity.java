package com.example.slip17qs2;

import android.os.Bundle;
import android.view.ContextMenu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    EditText num;
    TextView resultText;
    Button btn ;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main); // Connect to XML
        num = findViewById(R.id.number);
        resultText = findViewById(R.id.textView);
        btn = findViewById(R.id.button);
        registerForContextMenu(btn);
        btn.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                openContextMenu(v);
                return true;
            }
        });
    }
    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
        super.onCreateContextMenu(menu, v, menuInfo);
        menu.setHeaderTitle("Select an option:");
        menu.add(0, 1, 0, "Calculate Factorial");
        menu.add(0, 2, 0, "Calculate Sum of Digits");
    }
    @Override
    public boolean onContextItemSelected(MenuItem item) {
        String number = num.getText().toString().trim();
        if (number.isEmpty()) {
            Toast.makeText(MainActivity.this, "Please enter a number", Toast.LENGTH_SHORT).show();
            return true;
        }
        int n = Integer.parseInt(number);
        if (item.getItemId() == 1) {
            long fact = 1;
            for (int i = 1; i <= n; i++) fact *= i;
            resultText.setText("Factorial of " + n + " : " + fact);
        } else if (item.getItemId() == 2) {
            long sum = 0;
            int temp = n;
            while (temp != 0) {
                sum += (temp % 10);
                temp = temp / 10;
            }
            resultText.setText("Sum of " + n + " : " + sum);
        }
        return true;
    }
}
