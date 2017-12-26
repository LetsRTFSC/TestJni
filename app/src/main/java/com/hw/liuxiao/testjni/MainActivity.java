package com.hw.liuxiao.testjni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {


    TextView tv  = null;
    Button btn  = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tv = findViewById(R.id.textview);
        btn = findViewById(R.id.button);

        final TestJni testJni = new TestJni();
        int result = testJni.add(3,4);


        tv.setText("result is :"+result);


        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int[] arr = new int[]{3,4,57,8};
                testJni.gray(arr);
            }
        });

    }
}
