package com.example.slip17qs1;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    EditText phn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        Button btn = findViewById(R.id.button);
        phn = findViewById(R.id.editTextText);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                makecall();
            }
        });

    }
    private void makecall(){
        String phone = phn.getText().toString();
        if(phone.isEmpty()){
            Toast.makeText(MainActivity.this,"please enter a phone number ",Toast.LENGTH_LONG).show();
        }
        else{
            if(ContextCompat.checkSelfPermission(this, Manifest.permission.CALL_PHONE)!= PackageManager.PERMISSION_GRANTED){
                ActivityCompat.requestPermissions(this,new String[]{Manifest.permission.CALL_PHONE},1);
            }
            else{
                Intent call = new Intent(Intent.ACTION_CALL);
                call.setData(Uri.parse("tel:"+phone));
                startActivity(call);
            }
        }
    }
    @Override
    public void onRequestPermissionsResult(int requestcode,String[] permissions, int[] grantresult){
        super.onRequestPermissionsResult(requestcode,permissions,grantresult);
        if(requestcode == 1){
            if(grantresult.length >0 && grantresult[0] == PackageManager.PERMISSION_GRANTED){
                makecall();
            }
            else{
                Toast.makeText(MainActivity.this,"permission denied ",Toast.LENGTH_LONG).show();

            }
        }
    }
}