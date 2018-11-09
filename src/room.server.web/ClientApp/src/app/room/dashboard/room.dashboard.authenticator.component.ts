import { OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Router } from '@angular/router';
import { RoomDashboardAuthenticator } from './room.dashboard.authenticator';

export abstract class RoomDashboardAuthenticatorComponent implements OnInit {

  protected Router: Router;
  protected Http: HttpClient;
  protected BaseUrl: string;

  constructor(router: Router, http: HttpClient, baseUrl: string) {
    this.Router = router;
    this.Http = http;
    this.BaseUrl = baseUrl;
  }

  public ngOnInit() {
    var _self = this;

    var authenticator: RoomDashboardAuthenticator = new RoomDashboardAuthenticator(this.Http, this.BaseUrl);
    authenticator.authenticate(function () {
      _self.onInit();
    }, function () {
      _self.Router.navigate(['/room']);
    });
  }

  protected abstract onInit(): void;

}
