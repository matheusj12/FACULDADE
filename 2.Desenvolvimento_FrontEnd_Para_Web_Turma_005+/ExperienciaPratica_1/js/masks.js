// Máscara CPF
document.getElementById("cpf").addEventListener("input", function () {
    let v = this.value.replace(/\D/g, "");
    if (v.length > 11) v = v.slice(0, 11);
    v = v.replace(/(\d{3})(\d)/, "$1.$2");
    v = v.replace(/(\d{3})(\d)/, "$1.$2");
    v = v.replace(/(\d{3})(\d{1,2})$/, "$1-$2");
    this.value = v;
});

// Máscara Telefone
document.getElementById("tel").addEventListener("input", function () {
    let v = this.value.replace(/\D/g, "");
    if (v.length > 11) v = v.slice(0, 11);
    v = v.replace(/(\d{2})(\d)/, "($1) $2");
    v = v.replace(/(\d{1})(\d{4})$/, "$1 $2");
    v = v.replace(/(\d{4})(\d)/, "$1-$2");
    this.value = v;
});

// Máscara CEP
document.getElementById("cep").addEventListener("input", function () {
    let v = this.value.replace(/\D/g, "");
    if (v.length > 8) v = v.slice(0, 8);
    v = v.replace(/(\d{5})(\d)/, "$1-$2");
    this.value = v;
});
