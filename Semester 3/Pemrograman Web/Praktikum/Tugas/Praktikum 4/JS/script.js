// Game

let fighter1 = {
  nama: "Goku",
  skill: 9,
  tenaga: 500,
  pukul: function(){
      this.tenaga = this.tenaga - (5 * this.skill);
  },
  tendang: function(){
      this.tenaga = this.tenaga - (7 * this.skill);
  },
  lari: function(){
      this.tenaga = this.tenaga - (3 * this.skill);
  },
  jurusandalan: function(){
      this.tenaga = this.tenaga - (10 * this.skill);
  },
  makan: function(kalori){
      this.tenaga = this.tenaga + (10 * kalori)
  }
};

console.log("Nama Fighter : " + fighter1.nama);
console.log("Tenaga Awal : " + fighter1.tenaga);
fighter1.pukul();
fighter1.pukul();
fighter1.pukul();
console.log("Tenaga Setelah 3x Pukul : " + fighter1.tenaga);
fighter1.makan(35);
console.log("Tenaga Setelah Makan : " + fighter1.tenaga);

// Method

function jumlah(a, b){
  let c = a + b;
  return c;
}

