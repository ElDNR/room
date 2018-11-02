import { Component, Inject, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Router } from '@angular/router';

@Component({
  selector: 'app-roomdashboard',
  templateUrl: './room.dashboard.component.html'
})
export class RoomDashboardComponent implements OnInit {

  private Router: Router;
  private Http: HttpClient;
  private BaseUrl: string;

  constructor(router: Router, http: HttpClient, @Inject('BASE_URL') baseUrl: string) {
    this.Router = router;
    this.Http = http;
    this.BaseUrl = baseUrl;
  }

  protected ngOnInit() {
    // Check if authorized.
    this.Http
      .get(this.BaseUrl + 'api/Room/LoggedIn')
      .subscribe(result => {
        if (result == false) {
          this.Router.navigate(['/room']);
        }
      }, error => console.error(error));
  }

}
