= 0; i < n; i++){
        cout << name[i] << " ";
        cout << sons[i].size() << " ";
        for(auto x: sons[i]){
            cout << x << " ";
        }  
        cout << "\n";
    }