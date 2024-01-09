<?php
// 1. Verifica che il file sia stato caricato
if (isset($_FILES['file'])) {
    // 2. Verifica che non ci siano errori
    if ($_FILES['file']['error'] == 0) {
        // 3. Verifica che il file non sia troppo grande
        if ($_FILES['file']['size'] <= 1000000) {
            // 4. Verifica che il file sia del tipo giusto
                // 5. Sposta il file nella cartella desiderata
                move_uploaded_file($_FILES['file']['tmp_name'], 'uploads/' . $_FILES['file']['name']);
                echo 'File caricato con successo';
        } else {
            echo 'Il file è troppo grande';
        }
    } else {
        echo 'Si è verificato un errore';
    }
} else {
    echo 'Nessun file è stato caricato';
}
?>