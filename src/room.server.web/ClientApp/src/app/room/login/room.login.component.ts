import { Component, Inject } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Router } from '@angular/router';

@Component({
  selector: 'app-room',
  templateUrl: './room.login.component.html',
})
export class RoomLoginComponent {

  private Router: Router;
  private Http: HttpClient;
  private BaseUrl: string;

  public User = { UserName: "admin", Password: "admin" };

  constructor(router: Router, http: HttpClient, @Inject('BASE_URL') baseUrl: string) {
    this.Router = router;
    this.Http = http;
    this.BaseUrl = baseUrl;
  }

  public submitLogin() {
    this.Http
      .post(this.BaseUrl + 'api/Room/Login', this.User)
      .subscribe(result => {
        window.location.href = this.BaseUrl + 'room/dashboard';
        this.Router.navigate(['/room/dashboard']);
      }, error => console.error(error));
  }

}
