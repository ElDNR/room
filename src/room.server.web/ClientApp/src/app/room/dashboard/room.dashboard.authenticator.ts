import { HttpClient } from '@angular/common/http';

export class RoomDashboardAuthenticator {

  private Http: HttpClient;
  private BaseUrl: string;

  constructor(http: HttpClient, baseUrl: string) {
    this.Http = http;
    this.BaseUrl = baseUrl;
  }

  public authenticate(successCallBack: Function, failureCallBack: Function) {
    // Check if authorized.
    this.Http
      .get(this.BaseUrl + 'api/Room/LoggedIn')
      .subscribe(result => {
        if (result == false) {
          failureCallBack();
        } else {
          successCallBack();
        }
      }, error => console.error(error));
  }

}
