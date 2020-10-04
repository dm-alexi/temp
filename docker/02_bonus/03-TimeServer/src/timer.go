package main

import (
	"fmt"
	"net/http"
	"time"
)

func timeHandler(w http.ResponseWriter, r *http.Request) {
	t := time.Now().Format(time.RFC1123)
	body := "Sever time is:"
	fmt.Fprintf(w, "<h1 align=\"center\">%s</h1>", body)
	fmt.Fprintf(w, "<h2 align=\"center\">%s</h2>", t)
	fmt.Printf("Served time for: %s\n", r.Host)
}

func main() {
	PORT := ":80"
	http.HandleFunc("/", timeHandler)
	err := http.ListenAndServe(PORT, nil)
	if err != nil {
		fmt.Println(err)
		return
	}
}
