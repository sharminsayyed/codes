package com.example.slip14qs2;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import java.io.File;

public class MainActivity extends AppCompatActivity {

    private static final int PICK_FILE_REQUEST = 1;
    EditText editTextTo, editTextSubject, editTextMessage;
    Button buttonAttach, buttonSend;
    Uri fileUri;  // Store file URI

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editTextTo = findViewById(R.id.editTextTo);
        editTextSubject = findViewById(R.id.editTextSubject);
        editTextMessage = findViewById(R.id.editTextMessage);
        buttonAttach = findViewById(R.id.buttonAttach);
        buttonSend = findViewById(R.id.buttonSend);

        // Select File
        buttonAttach.setOnClickListener(view -> selectFile());

        // Send Email
        buttonSend.setOnClickListener(view -> sendEmail());
    }

    private void selectFile() {
        Intent intent = new Intent(Intent.ACTION_GET_CONTENT);
        intent.setType("*/*");
        intent.addCategory(Intent.CATEGORY_OPENABLE);
        startActivityForResult(Intent.createChooser(intent, "Select File"), PICK_FILE_REQUEST);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == PICK_FILE_REQUEST && resultCode == RESULT_OK && data != null) {
            fileUri = data.getData();
            Toast.makeText(this, "File Selected: " + fileUri.getPath(), Toast.LENGTH_SHORT).show();
        }
    }

    private void sendEmail() {
        String recipient = editTextTo.getText().toString();
        String subject = editTextSubject.getText().toString();
        String message = editTextMessage.getText().toString();

        Intent emailIntent = new Intent(Intent.ACTION_SEND);
        emailIntent.setType("message/rfc822");
        emailIntent.putExtra(Intent.EXTRA_EMAIL, new String[]{recipient});
        emailIntent.putExtra(Intent.EXTRA_SUBJECT, subject);
        emailIntent.putExtra(Intent.EXTRA_TEXT, message);

        if (fileUri != null) {
            emailIntent.putExtra(Intent.EXTRA_STREAM, fileUri);
        }

        try {
            startActivity(Intent.createChooser(emailIntent, "Choose an email client"));
            Toast.makeText(this, "Email Sent Successfully!", Toast.LENGTH_SHORT).show();
        } catch (Exception e) {
            Toast.makeText(this, "No email client found!", Toast.LENGTH_SHORT).show();
        }
    }
}
