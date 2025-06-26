/*. Create a Simple Application, that performs Arithmetic Operations. (Use constraint
layout)*/
package com.example.slip4sq1;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
public class MainActivity extends AppCompatActivity {
    EditText num1 ,num2 ; Button b1,b2,b3,b4;
    TextView result ;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main); // connect ot the xml
        // find view by id
        num1 = findViewById(R.id.num1);
        num2 = findViewById(R.id.num2);
        result = findViewById(R.id.textView);
        b1 = findViewById(R.id.add);
        b2 = findViewById(R.id.sub);
        b3 = findViewById(R.id.mult);
        b4 = findViewById(R.id.div);
        b1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                calculate('+');
            }
        });
        b2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                calculate('-');
            }
        });

        b3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                calculate('*');
            }
        });
        b4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                calculate('/');
            }
        });


    }
    private void calculate(char op){
        Double n1 = Double.parseDouble(num1.getText().toString());
        Double n2  = Double.parseDouble(num2.getText().toString());
        Double res = (op == '+') ? n1+n2 :
                        (op == '-') ? n1-n2 :
                            (op == '*')? n1*n2:
                                    (n2 != 0 ? n1/n2 :0);

        result.setText("Result :"+res);
    }
}