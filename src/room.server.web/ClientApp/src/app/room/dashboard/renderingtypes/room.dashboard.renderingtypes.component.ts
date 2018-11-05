import { Component, Inject, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Router } from '@angular/router';
import { RoomDashboardAuthenticator } from '../room.dashboard.authenticator';

@Component({
  selector: 'app-roomdashboardrenderingtypes',
  templateUrl: './room.dashboard.renderingtypes.component.html'
})
export class RoomDashboardRenderingTypesComponent implements OnInit {

  private Router: Router;
  private Http: HttpClient;
  private BaseUrl: string;

  constructor(router: Router, http: HttpClient, @Inject('BASE_URL') baseUrl: string) {
    this.Router = router;
    this.Http = http;
    this.BaseUrl = baseUrl;
  }

  public ngOnInit() {
    var _self = this;

    var authenticator: RoomDashboardAuthenticator = new RoomDashboardAuthenticator(this.Http, this.BaseUrl);
    authenticator.authenticate(function () {
      console.log("RoomDashboardRenderingsTypesComponent authenticated.");
    }, function () {
      _self.Router.navigate(['/room']);
    });
  }

}
