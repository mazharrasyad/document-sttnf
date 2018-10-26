function otentikasi(form) 
{
    if(form.username.value == "a" && form.password.value == "b") 
    {   
        alert("===== Login Sukses =====");          
        location = "profile.html";
    }         
    else 
    { 
        alert("===== Login Gagal =====");
    }
}

function kursvalas()
{
    let pilihan = document.getElementById("pilihvalas").value;
    let simpan = document.getElementById("nilai").value;
    let konversi = 0;
    if(pilihan == "us"){
        konversi = simpan * 9915;
    }
    else if(pilihan == "ds"){
        konversi = simpan * 13472;
    }
    else if(pilihan == "rm"){
        konversi = simpan * 874;
    }
    else if(pilihan == "yj"){
        konversi = simpan * 120;
    }
    else if(pilihan == "eu"){
        konversi = simpan * 15888;
    }
    else if(pilihan == "ra"){
        konversi = simpan * 3592;
    }    
    document.getElementById("rupiah").innerHTML = "Rp" + konversi;
}

function kirimpesan()
{
    let ambil = document.getElementById("pesan").value;
    if(ambil != "")
    {
        document.getElementById("chat").innerHTML += ambil + "\n";
    }    
}

function imagepick()
{    
    let pilihan = document.getElementById("pilihimage").value;
    let ganti;
    let img;

    if(pilihan == "sp"){
        img = document.getElementById("tampil").src = "image/sepeda.png";        
    }
    else if(pilihan == "mt"){
        img = document.getElementById("tampil").src = "image/motor.jpeg";
    }
    else if(pilihan == "mb"){
        img = document.getElementById("tampil").src = "image/mobil.jpeg";
    }
    else if(pilihan == "pr"){
        img = document.getElementById("tampil").src = "image/perahu.png";
    }
    else if(pilihan == "kr"){
        img = document.getElementById("tampil").src = "image/kereta.png";
    }
    else if(pilihan == "ps"){
        img = document.getElementById("tampil").src = "image/pesawat.png";
    }        
    
    ganti = img.replace("image/", "");
    alert("Ini Gambar " + ganti);
}

function submitform()
{
    let vnama = document.getElementById("nama").value;
    let vemail = document.getElementById("email").value;
    let vjam = document.getElementById("jam").value;
    let vtujuan = document.getElementById("tujuan").value;
    let vtiket = document.getElementById("tiket").value;

    let atpos = vemail.indexOf("@");
    let dotpos = vemail.lastIndexOf(".");    

    let fhasil = document.getElementById("fhasil");

    if(vnama == "")
    {
        document.getElementById("vnama").innerHTML = "Tidak Boleh Kosong";
        return false;
    }
    else
    {
        if(30 < vnama.length)
        {
            document.getElementById("vnama").innerHTML = "Tidak Boleh Dari 30 Karakter";
            return false;
        }
        else
        {
            document.getElementById("vnama").innerHTML = "";
            document.getElementById("hnama").innerHTML = vnama;
        }    
    }

    if(vemail == "")
    {
        document.getElementById("vemail").innerHTML = "Tidak Boleh Kosong";
        return false;
    }
    else 
    {
        if (atpos < 1 || dotpos < atpos + 2 || dotpos + 2 >= vemail.length) 
        {
            document.getElementById("vemail").innerHTML = "Format Email Salah";
            return false;
        }   
        else
        {
            document.getElementById("vemail").innerHTML = "";
            document.getElementById("hemail").innerHTML = vemail;
        }     
    }

    if(vjam == "")
    {
        document.getElementById("vjam").innerHTML = "Tidak Boleh Kosong";
        return false;
    }
    else
    {
        document.getElementById("vjam").innerHTML = "";  
        document.getElementById("hjam").innerHTML = vjam;      
    }

    if(vtujuan == "")
    {
        document.getElementById("vtujuan").innerHTML = "Tidak Boleh Kosong";
        return false;
    }
    else
    {
        document.getElementById("vtujuan").innerHTML = "";      
        document.getElementById("htujuan").innerHTML = vtujuan; 
    }

    if(vtiket == "")
    {
        document.getElementById("vtiket").innerHTML = "Tidak Boleh Kosong";
        return false;
    }
    else
    {
        if(vtiket < 0 || 10 < vtiket || vtiket == 0)
        {
            document.getElementById("vtiket").innerHTML = "Hanya Boleh 1 - 10 Tiket";
            return false;
        }
        else
        {
            document.getElementById("vtiket").innerHTML = "";            
            document.getElementById("htiket").innerHTML = form.tiket.value;
            
            if (fhasil.style.display == "none") 
            {                                                
                fhasil.style.display = "block";                
            } 
        }        
    }        
}