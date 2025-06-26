/*Create an Android application to demonstrate phone call using Implicit Intent. 20marks
* Write an android code to make phone call using Intent. 10 marks (Slip17 )*/

package com.example.slip7qs2;
import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

public class MainActivity extends AppCompatActivity {

    EditText phoneno;
    Button btn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main); // connect to xml file
        //find view by id
        phoneno = findViewById(R.id.phonenumber);
        btn = findViewById(R.id.button); // on click of btn make call
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                makephonecall();
            }
        });
    }
    private void makephonecall(){
        String phno = phoneno.getText().toString();
        // check if it is empty
        if(phno.isEmpty()){
            Toast.makeText(MainActivity.this,"please enter a number",Toast.LENGTH_LONG).show();
        } else{
            if(ContextCompat.checkSelfPermission(this, Manifest.permission.CALL_PHONE)!= PackageManager.PERMISSION_GRANTED){
                // below function is written for this
                ActivityCompat.requestPermissions(this,new String[]{Manifest.permission.CALL_PHONE},1);
            }else{
                // create an intent to make a call
                Intent call = new Intent(Intent.ACTION_CALL);
                call.setData(Uri.parse("tel:" + phno));
                startActivity(call);
            }
        }
    }
    @Override
    public void onRequestPermissionsResult(int requestcode , String[] permissions ,int[] grantResult){
        super.onRequestPermissionsResult(requestcode,permissions,grantResult);
        if(requestcode == 1){
            if(grantResult.length >0 && grantResult[0] == PackageManager.PERMISSION_GRANTED){
                makephonecall();
            }else{
                Toast.makeText(MainActivity.this,"permission denied",Toast.LENGTH_SHORT).show();
            }
        }
    }
}
